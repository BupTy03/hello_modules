export module Triangle;

import <iostream>;
import <string_view>;

export struct Triangle {
   void Print() const { std::cout << "Hello, I'm Triangle!\n"; }
   std::string_view Name() const { return "Triangle"; }
};
