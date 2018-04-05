
namespace cppReview
{
    template<class T>
    class Repository
    {
    public:
        virtual T Get(int id)=0;
        virtual void Delete(int id)=0;
        virtual void Create(const T &obj)=0;
        virtual void Update(const T &obj)=0;
    };
}
