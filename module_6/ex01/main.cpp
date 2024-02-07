#include "Serializer.hpp"

int main()
{
	Data myData;
	myData.setDataValue(42);

	uintptr_t serializedPtr = Serializer::serialize(&myData);

	Data *deserializedPtr = Serializer::deserialize(serializedPtr);

	if (deserializedPtr == &myData && deserializedPtr->getDataValue() == myData.getDataValue())
		std::cout << "Serialization and deserialization successful!\n";
	else
		std::cout << "Serialization and deserialization failed!\n";
}
