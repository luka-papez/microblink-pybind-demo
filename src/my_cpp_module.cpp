#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <sstream>

struct Rectangle
{
    double x;
    double y;
    double width;
    double height;

    Rectangle union_with( Rectangle const & other ) noexcept
    {
        auto const new_x = std::min( x, other.x );
        auto const new_y = std::min( y, other.y );

        return
        {
            .x      = new_x,
            .y      = new_y,
            .width  = std::max( x + width , other.x + other.width  ) - new_x,
            .height = std::max( y + height, other.y + other.height ) - new_y
        };
    }
};

Rectangle central_rectangle() noexcept
{
    return { 0.25f, 0.25f, 0.5f, 0.5f };
}

PYBIND11_MODULE( my_cpp_module, m )
{
    m.doc() = "pybind11 bindings for your C++ code";

    pybind11::class_< Rectangle >( m, "Rectangle" )
        .def( pybind11::init< double, double, double, double >() )
        .def_readwrite( "x"                , &Rectangle::x                 )
        .def_readwrite( "y"                , &Rectangle::y                 )
        .def_readwrite( "width"            , &Rectangle::width             )
        .def_readwrite( "height"           , &Rectangle::height            )
        .def          ( "union_with"       , &Rectangle::union_with        )
        .def
        (
            "__repr__",
            []( const Rectangle & rect )
            {
                constexpr auto sep = ", ";
                return
                    std::string( "Rectangle: [" ) +
                    std::to_string( rect.x )      +
                    sep                           +
                    std::to_string( rect.y  )     +
                    sep                           +
                    std::to_string( rect.width )  +
                    sep                           +
                    std::to_string( rect.height ) +
                    "]";
            }
    );

    m.def( "central_rectangle", &central_rectangle, "returns a rectangle in the center" );
}
