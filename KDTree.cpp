
/**
 * Author: Mingwei zhong
 *
 */

#include "KDTree.h"
#include <cmath>
using namespace std;

KDTree::KDTree()
{
	root = NULL;
}


KDTree::~KDTree()
{
    clear(root);
}

void KDTree :: clear(KDNode*t )
{

    if(t == NULL)
    {
        return;
    }

    clear(t->left);

    clear(t->right);

    if(t->left == NULL && t->right == NULL)
    {
        delete t;
        t = NULL;
    }

}

void KDTree::insert(double x, double y, string city, string address)
{
	root = insert( x, y, city, address, root, 0);
}
KDNode* KDTree::insert(double x, double y, string city, string address, KDNode* t, int split){
	if( t == NULL)
    {
        t = new KDNode(x, y, city, address);

	}
	else
        {

		if (abs(x - t->x) <= 0.00001 && abs(y - t->y) <= 0.00001)
        {
			return t;
		}

		if (split == 0)
        {
			if (x < t->x)
			{

				t->left = insert(x, y, city, address, t->left, 1 - split);

			}
			else if (x > t->x)
            {
				t->right = insert(x, y, city, address, t->right, 1 - split);
			}
		}
		else
            {
			if (y < t->y)
			{
				t->left = insert(x, y, city, address, t->left, 1 - split);
			}
            else if (y > t->y)
            {
				t->right = insert(x, y, city, address, t->right, 1 - split);
			}
		}
	}
    return t;
}

void KDTree::getNearest(double x, double y, vector<KDNode*>& result)
{
	getNearest(x, y, root, result, 0);
}

void KDTree::getNearest(double x, double y, KDNode* root, vector<KDNode*>& result, int level)
{
	if(root != NULL )
    {
        result.push_back(root);

		if (level == 0)
        {
               if( x < root->x )
               {
                if(root->right != NULL)
               {
                  result.push_back(root->right);
                }
				getNearest(x, y, root->left, result, 1- level);
               }

               else if( x > root->x )
               {
                 if(root->left != NULL)
                 {
                   result.push_back(root->left);
                 }
				   getNearest(x, y, root->right, result, 1- level);
               }

        }

		else
        {
			if( y < root->y )
			{
			    if (root->right != NULL)
                {
                result.push_back(root->right);
               }
				getNearest(x, y, root->left, result, 1- level);

			}
          else if( y > root->y )
			{
			   if(root->left != NULL)
                {
			    result.push_back(root->left);
                }
				getNearest(x, y, root->right, result, 1- level);
			}
		}
    }
}










