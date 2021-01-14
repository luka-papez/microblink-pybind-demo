from build.my_cpp_module import Rectangle, central_rectangle  # type: ignore

rect1 = Rectangle(0.1, 0.2, 0.3, 0.4)

print(rect1)
print(rect1.union_with(central_rectangle()))
