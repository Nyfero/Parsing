#include "../inc/parsing.hpp"

class Parser {

    private:
        std::vector<std::string>    _args;
        size_t                      _size;
        std::vector<std::string>    _flags;

    public:
    // Constructors
        Parser(int ac, char **av);
        ~Parser();

    // Setters
        void                        Set_flags();

    // Getters
        size_t                      Get_size() const;
        std::vector<std::string>    Get_args() const;
        std::string                 Get_args_i(size_t i) const;
        std::vector<std::string>    Get_flags() const;
        std::string                 Get_flags_i(size_t i) const;

    // Checkers
        int                         Check_size_less_than(size_t i) const;
        int                         Check_size_greater_than(size_t i) const;

    //Throw
		class ToMuchArgs : public std::exception {
		
            public:
			    virtual const char* what() const throw();
		};

        class NotEnoughtArgs : public std::exception {

            public:
                virtual const char* what() const throw();
        };
};
