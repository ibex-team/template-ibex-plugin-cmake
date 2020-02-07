#include "TestPlugin01.h"

int
main (int argc, char *argv[])
{
  ibex::Interval I = answer_to_the_ultimate_question ();
  return I.contains (42) ? 0 : 1;
}
