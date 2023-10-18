#include "../inc/parsing.hpp"
#include "../class/Parser.hpp"

int main(int ac, char **av) {
    Parser parse(ac, av);


    if (!parse.Get_args().empty()) {
        for (size_t i = 0; i < parse.Get_size(); i++) {
            std::cout << "args[" << i << "] = " << parse.Get_args_i(i) << std::endl;
        }
        parse.Set_flags();
        if (!parse.Get_flags().empty()) {
            for (size_t i = 0; i < parse.Get_flags().size(); i++)
                std::cout << "flags[" << i << "] = " << parse.Get_flags_i(i) << std::endl;
        }
    }

    testeur(parse);
    return 0;
}

