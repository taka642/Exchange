#pragma
class OneMinuteBarDto {
private:

	// 高値
	std::string high;
	// 低値
	std::string low;
	// 始値
	std::string open;
	// 買い
	std::string bid;
	// 売り
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