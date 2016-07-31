#include <iostream>
#include <sstream>


int ** transpose_array(int ** array,
                       const int rlength,
                       const int clength){

  if(array == nullptr || rlength < 1 || clength < 1){
    std::cout << "The parameters aren't valid." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  int ** tarray;
  tarray = new int*[clength];  // allocate the length of rows
  for(int i = 0; i < clength; i++){
    // for each row allocate the length of columns
    tarray[i] = new int[rlength];
  }

  for (int i=0; i<rlength; i++){
    for (int j = 0; j< clength; j++){
      tarray[j][i] = array[i][j];
    }
  }
  return tarray;
}

void print_2d_array(int ** array, const int lines, const int columns){
  for(int i = 0; i < lines; i++){
    for(int j = 0; j < columns; j++) {
      std::cout << array[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int ** init_array(const int line, const int column){
  int ** array;
  array = new int * [line];
  for (int i = 0; i < line; i++){
    array[i] = new int[column];
  }
  std::string mystr;
  for(int i = 0; i<line; i++){
    for(int j = 0; j<column; j++ ){
      std::cout << "value[ " << i << " ][ " << j << " ] = ";
      std::getline(std::cin, mystr);
      std::stringstream(mystr) >> array[i][j];
    }
  }
  return array;
}

void destroy_2d_array(int ** array, const int line){
  if(array!=nullptr && line > 0){
    for(int i = 0; i< line; i++)
      delete array[i];
  }
  delete array;
}


int main() {
  int l = 0;
  int c = 0;
  std::string mystr;

  std::cout << "How many lines?" << std::endl;
  std::getline(std::cin, mystr);
  std::stringstream(mystr) >> l;
  std::cout << "How many columns" << std::endl;
  std::getline(std::cin, mystr);
  std::stringstream(mystr) >> c;

  int ** array = init_array(l, c);

  print_2d_array(array, l, c);

  int **tarray;
  tarray = transpose_array(array, l, c);

  print_2d_array(tarray, c, l);

  destroy_2d_array(array, l);
  destroy_2d_array(tarray, c);
  return 0;
}