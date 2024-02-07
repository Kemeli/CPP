#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer(){ }

Serializer::Serializer(Serializer const& obj){
	*this = obj;
}

Serializer::~Serializer(){}

Serializer& Serializer::operator=(Serializer const & obj){
	(void) obj;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
