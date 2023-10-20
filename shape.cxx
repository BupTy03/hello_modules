export module Shape;

import <variant>;
import <stdexcept>;

export {

template<typename... Types>
class ShapeImpl;

}

template<typename... Types>
class ShapeImpl
{
public:
   ShapeImpl() : impl_(std::monostate{}) {}

   template<typename S>
   explicit ShapeImpl(S s) : impl_(std::move(s)) {}

   void Print() const { std::visit([](auto&& s) { s.Print(); }, impl_); }
   std::string_view Name() const { return std::visit([](auto&& s) { return s.Name(); }, impl_); }

private:
   std::variant<Types...> impl_;
};
