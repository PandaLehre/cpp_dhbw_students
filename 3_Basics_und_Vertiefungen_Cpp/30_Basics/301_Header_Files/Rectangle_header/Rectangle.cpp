#include "Rectangle.hpp"

Rectangle::Rectangle() {}

Rectangle::Rectangle(double width, double height)
   : m_width(width)
   , m_height(height) {}

Rectangle::~Rectangle() {}

void Rectangle::setWidth(double width)
{
   m_width = width;
}


void Rectangle::setHeight(double height)
{
   m_height = height;
}


double Rectangle::calcArea()
{
   return m_height * m_width;
}
