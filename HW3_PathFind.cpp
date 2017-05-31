//BRIAN DUENAS
//5-30-17
// HW3_PathFind.cpp 
// for HW3, CSE 330, Spring 2017, Kerstin Voigt, May 2017
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>  
#include <stack>

using namespace std;

map<int,vector<int> > read_maze(string, int&, int&);
bool traverse_maze(map<int,vector<int> >, int, int);
vector<int> find_path(map<int,vector<int> >, int, int);
vector<vector<int> > all_paths(map<int,vector<int> >, int, int);
void print_path(vector<int>);

int main()
{
  map<int,vector<int> > maze;

  int start,goal;

  maze = read_maze("lab5_maze.txt",start,goal);

  //prints maze
  /* 
  typedef map<int,vector<int> >::const_iterator itr;
  for (itr i = maze.begin(); i != maze.end(); i++)
  {
  	cout << "Key: " << i->first << endl << "Values:" << endl;
  	typedef vector<int>::const_iterator iterator;
  	for (iterator j = i->second.begin(); j != i->second.end(); j++)
  		cout << " " << *j << endl;
  }
  */

  vector<vector<int> > allpaths;

  allpaths = all_paths(maze,1,36);

  if (allpaths.empty())
    cout << endl << endl << "There is no path" << endl << endl;
  else
  {
    for (int i = 0; i < allpaths.size(); i++)
	{
      print_path(allpaths[i]);
  	  cout << endl << endl;
	}
  }

  return 0;
}

map<int,vector<int> > read_maze(string mfile, int& from, int& to)
{
  map<int,vector<int> > maze;

  int start = 0;
  int goal = 0;

  ifstream inp;
  inp.open(mfile.c_str() ); //need the .c_str() to open a filneame var

  inp >> start >> goal;

  from = start;
  to = goal;


  int n;
  int next;
  for (int i = start; i <= goal; i++)
    {
      inp >> n;
      vector<int> neighs;
      for (int j = 1; j <= n; j++)
	{
	  inp >> next;
	  neighs.push_back(next);
	}
      maze[i] = neighs;
    }
  inp.close();
  return maze;
}

bool traverse_maze(map<int, vector<int> > maze, int start, int goal)
{
  queue<int> Q;
  Q.push(start);

  int curr;
  vector<int> neighs;

  while (!Q.empty())
    {
      curr = Q.front();
      //cout << "Next front off Q: " << curr << endl;
      Q.pop();
      if (curr == goal)
	return true;

      neighs = maze[curr];
      for (int i=0; i < neighs.size(); i++)
		Q.push(neighs[i]);
    }
  return false;
}
vector<int> find_path(map<int,vector<int> > maze, int start, int goal)
{
  queue<vector<int> > Q;

  vector<int> path;
  path.push_back(start);

  Q.push(path);

  vector<int> currpath;
  vector<int> neighs;

  while (!Q.empty())
    {
      currpath = Q.front();
      //cout << "Next front off Q: " << curr << endl;
      Q.pop();

      if (currpath.back() == goal)
	return currpath; 

      neighs = maze[currpath.back()];
      for (int i=0; i < neighs.size(); i++)
	{
	  vector<int> nextpath(currpath); // uses copy constructor;
	  nextpath.push_back(neighs[i]);
	  Q.push(nextpath);
	}
    }
      
  vector<int> nopath;
  return nopath;
}

vector<vector<int> > all_paths(map<int,vector<int> > maze, int start, int goal)
{
  queue<vector<int> > Q;

  vector<vector<int> > allpaths;

  vector<int> path;
  path.push_back(start);
  Q.push(path);

  vector<int> currpath;
  vector<int> neighs;

  while (!Q.empty())
    {
      currpath = Q.front();
      Q.pop();

      if (currpath.back() == goal)
      	allpaths.push_back(currpath); //pushes found path into vector
      
      neighs = maze[currpath.back()]; //ask voigt how this array works/ returns value to index to value?
      /*
      int i=0;
      cout << endl << "NEIGHS SIZE: " << neighs.size() << " " << "NEIGHS VAL: "<< neighs[i] <<endl;
      i++;
      */
      for (int i=0; i< neighs.size(); i++)
      {
      	vector<int> nextpath(currpath); // copy constructor
      	nextpath.push_back(neighs[i]);
      	Q.push(nextpath);
      }

    }
  return allpaths;
}

void print_path(vector<int> v)
{
  cout << endl;
  cout << "Path: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}
