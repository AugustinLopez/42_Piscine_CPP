#ifndef CLASS_CONTACT_HPP
# define CLASS_CONTACT_HPP

# include <string>

class Contact {
    private:
        enum _index {FIRST_NAME, LAST_NAME, NICKNAME, LOGIN,
                     POSTAL_ADDRESS, EMAIL_ADDRESS, PHONE_NUMBER,
                     BIRTHDAY_DATE, FAVORITE_MEAL, UNDERWEAR_COLOR,
                     DARKEST_SECRET, INDEX_COUNT};
        std::string _elem[INDEX_COUNT];
        bool _initialized;
        void _elem_summary(_index) const;
    public:
        Contact(void);
        ~Contact(void);
        void add_from_io(void);
        void summary(int index) const;
        void info(void) const;
};

#endif