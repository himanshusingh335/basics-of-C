class Child:
    def __init__(self, name: str) -> None:
        self.name = name


class Student(Child):
    def __init__(self, marks: int, name: str) -> None:
        self.marks = marks
        Child.__init__(self, name)


student1 = Student(50, "Himanshu")
print(student1.name)
print(student1.marks)
