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
        Fixed &operator=(Fixed const &rhs);
        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
        Fixed operator+(Fixed const &rhs) const;
        Fixed operator-(Fixed const &rhs) const;
        Fixed operator*(Fixed const &rhs) const;
        Fixed operator/(Fixed const &rhs) const;
        bool operator>(Fixed const &rhs) const;
        bool operator<(Fixed const &rhs) const;
        bool operator>=(Fixed const &rhs) const;
        bool operator<=(Fixed const &rhs) const;
        bool operator==(Fixed const &rhs) const;
        bool operator!=(Fixed const &rhs) const;
        static Fixed &min(Fixed &f1, Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static const Fixed &min(Fixed const &f1, Fixed const &f2);
        static const Fixed &max(Fixed const &f1, Fixed const &f2);
    
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &val);
#endif
