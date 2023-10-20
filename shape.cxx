export module Shape;

import <variant>;
import <stdexcept>;

export {

template<typename... Types>
class ShapeImpl;

}

namespace detail {

struct ShapePrintVisitor
{
   void operator()(std::monostate) { throw std::runtime_error("Nothing to print!"); }

   template<typename T>
   void operator()(T&& v) { v.Print(); }
};

struct ShapeNameVisitor
{
   std::string_view operator()(std::monostate) { return {}; }

   template<typename T>
   std::string_view operator()(T&& v) { return v.Name(); }
};

}


template<typename... Types>
class ShapeImpl
{
public:
   ShapeImpl() : impl_(std::monostate{}) {}

   template<typename S>
   explicit ShapeImpl(S s) : impl_(std::move(s)) {}

   void Print() const { std::visit(detail::ShapePrintVisitor(), impl_); }
   std::string_view Name() const { return std::visit(detail::ShapeNameVisitor(), impl_); }

private:
   std::variant<std::monostate, Types...> impl_;
};
