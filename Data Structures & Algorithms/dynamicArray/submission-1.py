class DynamicArray:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.dynamicArray = [None] * self.capacity


    def get(self, i: int) -> int:
        return self.dynamicArray[i]

    def set(self, i: int, n: int) -> None:
        self.dynamicArray[i] = n

    def pushback(self, n: int) -> None:
        if self.capacity == self.size:
            self.resize()
        self.dynamicArray[self.size] = n
        self.size += 1

    def popback(self) -> int:
        self.size -= 1
        val = self.dynamicArray[self.size]
        self.dynamicArray[self.size] = None  # Clean up reference
        return val


    def resize(self) -> None:
        self.capacity *= 2
        newArray = [None] * self.capacity

        for i in range(len(self.dynamicArray)):
            newArray[i] = self.dynamicArray[i]
        self.dynamicArray = newArray

    def getSize(self) -> int:
        return self.size
    
    def getCapacity(self) -> int:
        return self.capacity
