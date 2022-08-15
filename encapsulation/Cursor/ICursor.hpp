/*
** EPITECH PROJECT, 2022
** indie
** File description:
** ICursor
*/

#ifndef ICURSOR_HPP_
#define ICURSOR_HPP_

namespace ray {
    class ICursor {
        public:
            virtual ~ICursor() = default;
            virtual void showCursor(void) = 0;
            virtual void hideCursor(void) = 0;
            virtual bool isCursorHidden(void) = 0;
            virtual void enableCursor(void) = 0;
            virtual void disableCursor(void) = 0;
            virtual bool isCursorOnScreen(void) = 0;
    };

    class Cursor : virtual public ICursor {
        Cursor();
        ~Cursor();
        /**
         * @brief Shows cursor
         * 
         */
        void showCursor(void);
        /**
         * @brief Hides cursor
         * 
         */
        void hideCursor(void);
        /**
         * @brief Check if cursor is not visible
         * 
         * @return true 
         * @return false 
         */
        bool isCursorHidden(void);
        /**
         * @brief Enables cursor (unlock cursor)
         * 
         */
        void enableCursor(void);
        /**
         * @brief Disables cursor (lock cursor)
         * 
         */
        void disableCursor(void);
        /**
         * @brief Check if cursor is on the screen
         * 
         * @return true 
         * @return false 
         */
        bool isCursorOnScreen(void);
    };
}

#endif /* !ICURSOR_HPP_ */
