#pragma
class OneMinuteBarDto {
private:

	// ���l
	int high;
	// ��l
	int low;
	// �n�l
	int open;
	// ����
	int bid;
	// ����
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