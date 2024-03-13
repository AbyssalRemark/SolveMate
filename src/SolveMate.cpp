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
#include "graph.h" /* matrix graphs */
#include <iostream>
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

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    dsi::GraphMatrix<int> intGraph;
    //checking if compiler makes copy constructor
    dsi::GraphMatrix<int> graph2 = intGraph; 
    //returns empty vector if not in existance
    std::vector<int> first = graph2.getEdges(1); 
    std::cout << graph2 << std::endl;
    printVector(first);

    return 0;
}