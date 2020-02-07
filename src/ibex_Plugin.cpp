#include "ibex_Plugin.h"

ibex::Interval answer_to_the_ultimate_question ()
{
  ibex::Interval x(6,6), y(9-2,9+2);
  return x*y;
}
