export module Rectangle;

import <iostream>;
import <string_view>;

export struct Rectangle {
   void Print() const { std::cout << "Hello, I'm Rectangle!\n"; }
   std::string_view Name() const { return "Rectangle"; }
};
