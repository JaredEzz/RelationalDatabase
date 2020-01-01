cmake_minimum_required(VERSION 3.13)
project(RelationalDatabase)

set(CMAKE_CXX_STANDARD 14)

add_executable(RelationalDatabase main.cpp Database.cpp Database.h Relation.cpp Relation.h Tuple.cpp Tuple.h Scheme.cpp Scheme.h Parser.cpp Parser.h Datalog.cpp Datalog.h Rule.cpp Rule.h Predicate.cpp Predicate.h Parameter.cpp Parameter.h Scanner.cpp Scanner.h Token.cpp Token.h TokenType.h)