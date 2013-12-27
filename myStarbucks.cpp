#include "myStarbucks.h"

//Author:Mingwei zhong

 /*
   * Add all entries in the array to your data structure
   *
   * Note: If you detect that two items have the same coordinates, then do not add the new item
   *       that has the same coordinates as another item. This is guaranteed to happen, by the way,
   *       because some Starbucks locations are listed in the database twice. We will define two locations
   *       to be the "same location" if both |x1 - x2| <= 0.00001 and |y1 - y2| < 0.00001
   */
  void MyStarbucks::build(Entry* c, int n)
  {

      int m = n/2;


      for (int i = m ; i >= 0; i--)
      {
		  kdtree.insert(c[i].x, c[i].y, c->city, c->address);
	  }

      for(int i = m;i<n;i++)
      {
          kdtree.insert(c[i].x, c[i].y, c->city, c->address);

      }
  }

  /*
   * Return a pointer to the entry that is closest to the given coordinates. Your
   * answer may be approximate, but then you will lose points on the "Accuracy" quality measure
   */
  Entry* MyStarbucks::getNearest(double x, double y)
  {
	  vector<KDNode*> result;
	  kdtree.getNearest(x, y, result);
	  //cout << "result.size(): " << result.size() << endl;
	  if (result.size() == 0){
		  return NULL;
	  }
	  KDNode* minNode = result[0];
	  double minDistance = distance(x, y, minNode->x, minNode->y);
	  //cout << "minDistance: " << minDistance << endl;
	  for (std::vector<KDNode*>::iterator it = result.begin() ; it != result.end(); ++it){
		  double currentDistance = distance(x, y, (*(it))->x, (*(it))->y);

		  if (currentDistance < 0){
			  cout << "ERROR: " << currentDistance << endl;
		  }
		  if ( currentDistance < minDistance){
			  minDistance = currentDistance;
			  minNode = *it;
			  //cout << "minDistance: " << minDistance << endl;
		  }
	  }
	  Entry* entry = new Entry();
	  entry->x = minNode->x;
	  entry->y = minNode->y;
	  entry->city = minNode->city;
	  entry->address = minNode->address;
	  return entry;
  }


