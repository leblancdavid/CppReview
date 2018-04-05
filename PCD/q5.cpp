#include <iostream>
#include <memory>

class ProgressLogger {
    public:
    virtual void log(int progress)=0;
};

class DataProcessor {
public:

    DataProcessor(const std::shared_ptr<ProgressLogger> &progressLogger)
    {
        _progressLogger = progressLogger;
    }
    DataProcessor(const DataProcessor &cpy)
    {
        _progressLogger = cpy._progressLogger;
    }

    void processData() {
        for ( unsigned int progress = 0; progress <= 100; progress += 10 ) {
            _progressLogger->log(progress);
        }
    }
private:
    std::shared_ptr<ProgressLogger> _progressLogger;

    // this enforces the ProgressLogger to be injected into the DataProcessor
    DataProcessor() {}

};



class StdCoutProgressLogger : public ProgressLogger {
    public:
        StdCoutProgressLogger() {}
        StdCoutProgressLogger(const StdCoutProgressLogger &cpy) {}
        ~StdCoutProgressLogger() {}

        void log(int progress)
        {
            std::cout << progress << " percent done" << std::endl;
        }
};

int main() {

    DataProcessor dp(std::shared_ptr<ProgressLogger>(new StdCoutProgressLogger));
    dp.processData();
    return 0;
}