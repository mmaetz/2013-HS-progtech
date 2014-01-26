/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 10.2
 */

double integrate(const double a, const double b, const unsigned bins, const function& func)
{
  assert(bins > 0);
  assert(b >= a);

  const unsigned steps = 2*bins + 1;

  const double dr = (b - a) / (steps - 1);

  double I = func(a);
  
  for(unsigned i = 1; i < steps-1; ++i)
    I += 2 * (1.0 + i%2) * func(a + dr * i);

  I += func(b);
  
  return I * (1./3) * dr;
}
