#include <iostream>
#include <vector>

bool is_onto(int (*function)(int), std::vector<int> domain, std::vector<int> codomain) {
    for (int codomain_element : codomain) {
        bool element_mapped = false;
        
        for (int domain_element : domain) {
            if (function(domain_element) == codomain_element) {
                element_mapped = true;
                break;
            }
        }
        
        if (!element_mapped) {
            return false;
        }
    }
    
    return true;
};

int my_function(int x) {
    return x * 2;
}

int main()
{
    int n1, n2;
    std::vector<int> domain;
    std::vector<int> codomain;
    std::cout<<"Enter the number of elements in the domain:"<<std::endl;
    std::cin>>n1;
    std::cout << "Enter domain elements: ";
    for(int i=0;i<n1;i++)
    {
        std::cin>>domain[i];
    }
    std::cout<<"Enter the number of elements in the codomain:"<<std::endl;
    std::cin>>n2;
    std::cout << "Enter codomain elements: ";
    for(int i=0;i<n2;i++)
    {
        std::cin>>codomain[i];
    }
    bool result = is_onto(my_function, domain, codomain);
    std::cout << "Is the function onto? " << std::boolalpha << result << std::endl;
    return 0;
}

