/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** IDrawable
*/

#ifndef IDRAWABLE_HPP_
#define IDRAWABLE_HPP_

namespace ray {
    class IDrawable {
    public:
        virtual ~IDrawable() = default;
        virtual void draw() const = 0;
    };
};

#endif /* !IDRAWABLE_HPP_ */
