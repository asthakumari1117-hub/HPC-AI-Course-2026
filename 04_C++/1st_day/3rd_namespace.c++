# include <iostream>
namespace ptu
{
    void display()
    {
        std::cout << "astha from ptu \n";
    }
}
namespace hpc
{
    void display()
    {
        std::cout << "astha from hpc \n";
    }
}

int main()
{
    // using namespace ptu;
    // using namespace hpc;
    // display();
    ptu::display();
    hpc::display();

}