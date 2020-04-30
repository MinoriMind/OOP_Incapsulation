#include <iostream>
#include <string>

using namespace std;

class Mortal
{
    int age = 0;
public:
    string name;
    int enemykilled = 0;

    void SetAge(int _age)
    {
        age = _age;
    };

    int GetAge()
    {
        return age;
    };

    int DecreaseAgeByTen()
    {
        age-=10;
    };

    virtual void AskAboutWeather()
    {
        cout << "How is the weather?" << endl;
    };

    virtual void KillEnemy()
    {
        enemykilled++;
    };
};


class Immortal: public Mortal
{
public:
    void AskAboutWeather()
    {
        cout << "Weather will be good, right?" << endl;
    };

    void KillEnemy()
    {
        Mortal::KillEnemy();
        cout << "I didn't want to do this..." << endl;
    };
};


void QuestionWeather(Mortal *m)
{
    m->AskAboutWeather();
};


void KillMyEnemy(Mortal *m)
{
    m->KillEnemy();
};


int main() {
    Mortal human;
    Immortal elf;
    human.name = "Person";
    cout << human.name << endl;     //Oтсутствие инкапсуляции
    human.SetAge(27);          //Инкапсуляция с помощью set/get
    cout << human.GetAge() << endl;
    human.DecreaseAgeByTen();       //Инкапсуляция с помощью специализированных протоколов/методов
    cout << human.GetAge() << endl;
    QuestionWeather(&human);        //Инкапсуляция через позднее связывание и замена поведения
    QuestionWeather(&elf);
    KillMyEnemy(&human);            //Инкапсуляция через позднее связывание и расширения поведения
    cout << "Enemy killed by human " << human.enemykilled << endl;
    KillMyEnemy(&elf);
    cout << "Enemy killed by elf " << elf.enemykilled << endl;
    return 0;
}
