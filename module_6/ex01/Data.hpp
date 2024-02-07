#ifndef DATA_HPP
#define DATA_HPP

class Data {
public:
	Data();
	Data(const Data &obj);
	Data &operator=(const Data &obj);
	~Data();

	int getDataValue() const;
	void setDataValue(int value);

private:
	int dataValue;
};

#endif
