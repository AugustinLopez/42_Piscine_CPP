#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed {
    private:
        int _fix;
        static const int _lfraction;

    public:
        Fixed(void);
        Fixed(Fixed const &copy);
        Fixed(const int val);
        Fixed(const float val);
        ~Fixed(void);
        Fixed &operator=(Fixed const &equal);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &val);
#endif
