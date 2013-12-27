Author : Mingwei zhong

#include "Starbucks.h"
#include "KDTree.h"
#include <ctime>
#include <vector>

using namespace std;

class MyStarbucks: public Starbucks{
public:
 /*
   * add all entries in the array to your data structure
   *
   * Note: If you detect that two items have the same coordinates, then do not add the new item
   *       that has the same coordinates as another item. This is guaranteed to happen, by the way,
   *       because some Starbucks locations are listed in the database twice. We will define two locations
   *       to be the "same location" if both |x1 - x2| <= 0.00001 and |y1 - y2| < 0.00001
   */
  virtual void build(Entry* c, int n);

  /*
   * Return a pointer to the entry that is closest to the given coordinates. Your
   *  answer may be approximate, but then you will lose points on the "Accuracy" quality measure
   */
  virtual Entry* getNearest(double x, double y);
private:
	KDTree kdtree;
};
