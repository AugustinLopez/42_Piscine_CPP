#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
    private:
        int _fix;
        static const int _lfraction;

    public:
        Fixed(void);
        Fixed(Fixed const &copy);
        ~Fixed(void);
        Fixed &operator=(Fixed const &equal);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
