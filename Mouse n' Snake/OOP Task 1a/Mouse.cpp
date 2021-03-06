#include "Mouse.h"
#include "RandomNumberGenerator.h"

Mouse::Mouse() : MovableGridItem(MOUSE, x, y), alive(true), escaped(false), mouse_dx(0), mouse_dy(0)
{
   //position_in_middle_of_grid();
	position_at_random();
}

bool Mouse::is_alive() const
{
   return alive;
}

void Mouse::reset() {
	alive = true;
	escaped = false;
	mouse_dx = 0;
	mouse_dy = 0;
	position_at_random();
}

bool Mouse::has_escaped() const
{
   return escaped;
}

bool Mouse::has_reached_a_hole(const Underground& ug)
{
   for (int h_no = 0; h_no < (int) ug.getHoles().size(); ++h_no)
   {
      /*Hole h = ug.get_hole_no(h_no);*/

      if (is_at_position(ug.get_hole_no(h_no).get_x(), ug.get_hole_no(h_no).get_y()))
      {
         return true;
      }
   }

   return false;
}

void Mouse::die()
{
   alive = false;
}

void Mouse::escape_into_hole()
{
   escaped = true;
}

void Mouse::scamper(const int& key)
{
   switch (key)
   {
      case KEY_LEFT:
         mouse_dx = -1;
         mouse_dy = 0;
         break;
      case KEY_RIGHT:
         mouse_dx = +1;
         mouse_dy = 0;
         break;
      case KEY_UP:
         mouse_dx = 0;
         mouse_dy = -1;
         break;
      case KEY_DOWN:
         mouse_dx = 0;
         mouse_dy = +1;
         break;
      default:
         // not a key we care about, so do nothing
         break;

  }

   // update mouse coordinates if move is possible
   if (((x + mouse_dx) >= 1) && ((x + mouse_dx) <= SIZE) && ((y + mouse_dy) >= 1) && ((y + mouse_dy) <= SIZE))
   {
      update_position(mouse_dx, mouse_dy);
   }
}


//void Mouse::position_in_middle_of_grid()
//{
//   x = SIZE / 2;
//   y = SIZE / 2;
//}

void Mouse::position_at_random() {
	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
}