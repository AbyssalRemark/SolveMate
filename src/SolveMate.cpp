/*!****************************************************************************\

  \file   SolveMate.c
  \author Dominic Severe
  \date   2/14/2024

  \par            email:  dominicsevere\@gmail.edu
  \par          project:  SolveMate

  \brief
      For now just a driver for testing Graphs
  
      Functions include:
  
         +main
  
    Cohesive Responsibility:
      Start of program
  
    Notable portions:
      Nothing worth mentioning 

\******************************************************************************/
/**********************************************************\
 *    Includes 
\**********************************************************/
#include <iostream> /* cout and other printing things */
#include <random>   /* random gen stuff.              */
#include "graph.h"  /* matrix graphs.                 */
/**********************************************************\
 *    Macros  
\**********************************************************/
//Silences Unused Parameter in a fun and healthy way
#define UNUSED(expr) (void)(expr)

//Namespace Shortenner because alias is gross.
namespace dsi = DominicsSelfImplement; 

template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "vector:" << std::endl;
    for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test0()
{
    dsi::GraphMatrix<int> intGraph;
    //checking if compiler makes copy constructor
    dsi::GraphMatrix<int> graph2 = intGraph; 
    //returns empty vector if not in existance
    std::vector<int> first = graph2.getEdges(1); 
    std::cout << graph2 << std::endl;
    printVector(first);
}

//tests matrix with some random number generation. not a horribly useful graph...
void test1()
{
    int size = 8;
    int upperbound = 10;
    //I seed a complex random number generator with 0 for consistency.. *sigh*
    std::mt19937 gen(0);
    //a tool for uniform random numbers in a range...
    std::uniform_int_distribution<> distrib(0, upperbound);

    dsi::GraphMatrix<int> intGraph =  dsi::GraphMatrix<int>(size);
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            //a cheep way to make a lot of things 0
            if(distrib(gen) > upperbound / 2)
                intGraph.addEdge(i, j, distrib(gen));
        }
    }
    std::cout << intGraph << std::endl;
}

void test2()
{
    dsi::GraphMatrix<int> intGraph = dsi::GraphMatrix<int>(6);
    std::vector<int> res;

    intGraph.addSymEdge(0,1,10);
    intGraph.addSymEdge(0,2,20);
    intGraph.addSymEdge(1,3,50);
    intGraph.addSymEdge(1,4,10);
    intGraph.addSymEdge(2,3,33);
    intGraph.addSymEdge(3,4,20);
    intGraph.addSymEdge(3,5,2);
    intGraph.addSymEdge(4,5,1);
    std::cout << intGraph << std::endl;

    //printVector<int>(intGraph.dijkstras(0));
    res = intGraph.dijkstras(0);
    printVector(res);

}

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    //int size = 8;
    //test1();
    //dsi::GraphMatrix<int> intGraph =  dsi::GraphMatrix<int>(size);

    test2();

    //intGraph.addEdge(0, 1, 8);
    //std::cout << intGraph << std::endl;

    return 0;
}