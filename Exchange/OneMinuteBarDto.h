#pragma
class OneMinuteBarDto {
private:

	// ���l
	std::string high;
	// ��l
	std::string low;
	// �n�l
	std::string open;
	// ����
	std::string bid;
	// ����
	std::string ask;

public:

	std::string getHigh() { return high; }
	void setHigh(std::string high) { this->high = high; }

	std::string getLow() { return low; }
	void setLow(std::string low) { this->low = low; }

	std::string getOpen() { return open; }
	void setOpen(std::string open) { this->open = open; }

	std::string getBid() { return bid; }
	void setBid(std::string bid) { this->bid = bid; }

	std::string getAsk() { return ask; }
	void setAsk(std::string ask) { this->ask = ask; }
};