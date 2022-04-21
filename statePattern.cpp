#include <iostream>
#include <cstring>

class Actor
{
private:
    bool currentSlapped;
    bool nextSlapped;
    std::string name;

public:
    Actor(std::string name) : currentSlapped(false), nextSlapped(false), name(name) {}

    virtual void update() = 0;
    virtual ~Actor() {}

    void reset()
    {
        bool switchTemp = currentSlapped;
        currentSlapped = nextSlapped;
        nextSlapped = switchTemp;
    }
    void sufferSlapping()
    {
        nextSlapped = true;
    }
    bool isSlapped()
    {
        return currentSlapped;
    }
    std::string getName() const
    {
        return name;
    }
};

class Comedian : public Actor
{
private:
    Actor *facedActor;

public:
    Comedian(Actor *actor, std::string name) : facedActor(actor), Actor(name) {}
    void SetFacedActor(Actor *actor) { facedActor = actor; }
    void update()
    {
        if (isSlapped())
        {
            facedActor->sufferSlapping();
            std::cout << getName() << ": slapped " << facedActor->getName() << std::endl;
        }
        else
        {
            std::cout << getName() << " do nothing." << std::endl;
        }
    }
};

class Stage
{
private:
    static const int ActorCount = 3;
    Actor *actors[ActorCount];

public:
    Stage()
    {
        actors[0] = new Comedian(nullptr, "A1");
        actors[1] = new Comedian(actors[0], "A2");
        actors[2] = new Comedian(actors[1], "A3");
        ((Comedian *)actors[0])->SetFacedActor(actors[2]);

        actors[2]->sufferSlapping();
    }
    void update()
    {
        for (int i = 0; i < ActorCount; i++)
        {
            actors[i]->update();
        }
        for (int i = 0; i < ActorCount; i++)
        {
            actors[i]->reset();
        }
        std::cout << "One turn finished" << std::endl;
    }
};

int main()
{
    Stage stage;

    char ch;
    ch = getchar();
    while (ch != 'x')
    {
        stage.update();
        ch = getchar();
    }

    return 0;
}
