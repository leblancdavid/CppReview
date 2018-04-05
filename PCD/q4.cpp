#include <iostream>
#include <vector>
#include <memory>
// assume all the necessary includes are here

class World {
    public:

  static int temperature; // celcius
  static int windSpeed; // miles per hour
};

int World::temperature = 0;
int World::windSpeed = 0;

class Bird 
{
    public:
    virtual void Fly()=0;
    virtual void Hop()=0;
    virtual double GetDistance()
    {
        return distance;
    }

    virtual std::string GetBirdType()
    {
        return birdType;
    }

    protected:
        double distance;
        std::string birdType;
};

class Penguin : public Bird
{
    public: 
        Penguin() { distance = 0; birdType = "penguin"; }
        Penguin(const Penguin &cpy) { distance = cpy.distance; birdType = cpy.birdType; }
        ~Penguin() { }

        void Fly()
        {
            //can't fly, so doesn't change distance
        }

        void Hop()
        {
            distance += 2.0;
        }
};

class Hawk : public Bird 
{
    public:
        Hawk() { distance = 0; birdType = "hawk"; }
        Hawk(const Hawk &cpy) { distance = cpy.distance; birdType = cpy.birdType; }
        ~Hawk() { }

        void Fly()
        {
            if(World::windSpeed <= 40)
            {
                distance += 100.0;
            }
        }

        void Hop()
        {
            //can't hop
        }
};

class Robin : public Bird
{
    public:
    Robin() { distance = 0; birdType = "robin";  }
    Robin(const Robin &cpy) { distance = cpy.distance; birdType = cpy.birdType; }
    ~Robin() { }

    void Fly()
    {
        if(World::windSpeed <= 20)
        {
            distance += 20.0;
        }
    }

    void Hop()
    {
        if(World::temperature >= 0)
        {
            distance += 1.0;
        }
    }
};

class Crow : public Bird
{
    public:
    Crow() { distance = 0; birdType = "crow";  }
    Crow(const Crow &cpy) { distance = cpy.distance; birdType = cpy.birdType; }
    ~Crow() { }

    void Fly()
    {
        if(World::windSpeed <= 25)
        {
            distance += 30.0;
        }
    }

    void Hop()
    {
        if(World::temperature >= 0)
        {
            distance += 1.0;
        }
    }
};


int main(int argc, const char* argv[]) {
  // TODO: create the birds here
  std::vector<std::shared_ptr<Bird>> birds{
  
      std::shared_ptr<Bird>(new Penguin()),
      std::shared_ptr<Bird>(new Hawk()),
      std::shared_ptr<Bird>(new Robin()),
      std::shared_ptr<Bird>(new Crow()),
  };


  World::temperature = 20;
  World::windSpeed = 12;
  
  // TODO: have each bird fly & hop
  for(auto& it : birds)
  {
      it->Fly();
      it->Hop();
  }

  // a storm arrives!
  World::temperature = -10;
  World::windSpeed = 30;

  // TODO: have each bird fly & hop
  for(auto& it : birds)
  {
      it->Fly();
      it->Hop();
  }
  // TODO: print total distances

for(auto& it : birds)
  {
      std::cout << "The " << it->GetBirdType().c_str() << " moved " << it->GetDistance() << "ft" << std::endl;
  }
  return 0;
};