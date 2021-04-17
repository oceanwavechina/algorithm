project(AlgorithmBOX_DP)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -g -std=c++14")

#if(0)

# cut_rode.cpp
set(cut_rode_SRC cut_rode.cpp)
add_executable(cut_rode ${cut_rode_SRC})

# longet_common_subsequence.cpp
set(longet_common_subsequence_SRC longet_common_subsequence.cpp)
add_executable(longet_common_subsequence ${longet_common_subsequence_SRC})

# most_profit_stock_trade_once.cpp
set(most_profit_stock_trade_once_SRC most_profit_stock_trade_once.cpp)
add_executable(most_profit_stock_trade_once ${most_profit_stock_trade_once_SRC})

# up_the_steps.cpp
set(up_the_steps_SRC up_the_steps.cpp)
add_executable(up_the_steps ${up_the_steps_SRC})

# word_break_problem.cpp
set(word_break_problem_SRC word_break_problem.cpp)
add_executable(word_break_problem ${word_break_problem_SRC})

# knapsack_with_repetitions.cpp
set(knapsack_with_repetitions_SRC knapsack_with_repetitions.cpp)
add_executable(knapsack_with_repetitions ${knapsack_with_repetitions_SRC})

# money_change.cpp
set(money_change_SRC money_change.cpp)
add_executable(money_change ${money_change_SRC})

#endif(0)





