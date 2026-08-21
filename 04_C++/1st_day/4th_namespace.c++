#include <iostream>

namespace Electronics 
{
    void display_personal_info()
    {
        std::cout <<"name:Rahul\n";
        std::cout <<"branch:electronics\n";
        std::cout <<"Roll_no:2228926\n";
    }
    void display_mrks()
    {
        std::cout << "Ec01 -78 \n Ec02-86 \nEc03 -83\nEc04-90 \n Ec05-98";
    }
}

int main()
{
    using Electronics::display_personal_info;
    display_personal_info;
    Electronics::display_mrks();
}