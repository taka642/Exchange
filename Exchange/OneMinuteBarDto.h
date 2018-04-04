#pragma
class OneMinuteBarDto {
private:

	// 高値
	int high;
	// 低値
	int low;
	// 始値
	int open;
	// 買い
	int bid;
	// 売り
	int ask;

public:

	int getHigh() { return high; }
	void setHigh(int high) { this->high = high; }

	int getLow() { return low; }
	void setLow(int low) { this->low = low; }

	int getOpen() { return open; }
	void setOpen(int open) { this->open = open; }

	int getBid() { return bid; }
	void setBid(int bid) { this->bid = bid; }

	int getAsk() { return ask; }
	void setAsk(int ask) { this->ask = ask; }
};