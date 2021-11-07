#ifndef KAREN_HPP
# define KAREN_HPP

#include <string>

class Karen {
    public:
        typedef void (Karen::*funPtr)(void) const;
        Karen(void);
        ~Karen(void);
        void complain(std::string level) const;
    
    private:
        void _debug(void) const;
        void _info(void) const;
        void _warning(void) const;
        void _error(void) const;
        void _no_msg(void) const;
        const static std::string _msg[4];
        const static funPtr _fun_array[5];
};


#endif
