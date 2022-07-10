#ifndef convertPgnStringToArrayOfSanMoves_cpp
#define convertPgnStringToArrayOfSanMoves_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
input: string containing a chess game's pgn
output: vector containing each of the moves in order
-----------------------------------------------------------------*/
#include <utility>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>


#include <ezprint.cpp>

namespace chl {

const std::vector<char> move_indicating_chars = {
  'a', 'b', 'c', 'd', 'e', 'f',  'g',  'h',
  'K', 'Q', 'R', 'B', 'N'};

std::vector<size_t> getPositionsOfMovesInPgnString(const std::string& pgn) {
  
  std::vector<size_t> move_indices;
  const size_t pgn_length = pgn.length();
  int move = 1;
  while(move < 1000) {
    
    /* convert move to string */
    std::stringstream move_buffer;
    move_buffer << move;
    std::string move_string = move_buffer.str();
    std::string search_string = move_string + ". ";
    std::string alternative_search_string = move_string + ".\n";

    /* find the index of the move; break if not found (game is over) */
    size_t index = pgn.find(search_string);
    if (index > pgn_length) {
      size_t alternative_index = pgn.find(alternative_search_string);
      if(alternative_index > pgn_length) {
        break;
      } else {
        index = alternative_index;
      }
    }

    move_indices.push_back(index);
    ++move;
  }
  return move_indices;   
}


std::pair<size_t, size_t> getPositionsOfMovePairInPgnString(const size_t start_index, 
                                                            const std::string& pgn) {
  int i = static_cast<int>(start_index);
  size_t index_white_move;
  size_t index_black_move;

  while (i < start_index+5) {
    if (pgn[i] == ' ') { ++i; continue; }
    else if (std::count(move_indicating_chars.begin(), move_indicating_chars.end(), pgn[i])) {
      index_white_move = i;
      break;
    }
    ++i;
  }

  while (i < (i+10)) {
    if (pgn[i] != ' ') { ++i; continue; }
    if (pgn[i] == ' ' || pgn[i] == '\n') {
      break;
    }
  }
  
  while (i < (i+10)) {
    if (pgn[i] == ' ') { ++i; continue; }
    else if (std::count(move_indicating_chars.begin(), move_indicating_chars.end(), pgn[i])) {
      index_black_move = i;
      break;
    }
    ++i;
  }

  return std::make_pair(index_white_move, index_black_move);

}


std::string getMoveAtIndex(size_t index, const std::string& pgn) {
  std::string move;
  constexpr char empty = ' ';
  constexpr char enter_char = '\n';
  while (index < pgn.length()) {
    if (pgn[index] != empty && pgn[index] != enter_char) {
      move += pgn[index];
      ++index;
    } else {
      break;
    }
  }
  return move;
}


std::vector<std::string> convertPgnStringToArrayOfSanMoves(const std::string& pgn) {
  const std::vector<size_t> move_indices = getPositionsOfMovesInPgnString(pgn);
  std::vector<std::string> moves = {};

  for (auto const& move : move_indices) {
    const std::pair<size_t, size_t> move_pair_positions = getPositionsOfMovePairInPgnString(move, pgn);
    moves.push_back(getMoveAtIndex(move_pair_positions.first, pgn));
    moves.push_back(getMoveAtIndex(move_pair_positions.second, pgn));
  }

  // for (auto const& move : moves) {
    // ezp::print_item(move);
  // }

  return moves;
}


}




#endif /* convertPgnStringToArrayOfSanMoves_cpp */
