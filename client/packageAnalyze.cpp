


class packageAnalyze {
private:
	int packageNum;
	int packageLength;
	char buffer[MAXSIZE];
public:
	packageAnalyze() {
		packageNum = 0;
		packageLength = 0;
		memset(buffer, 0, sizeof(buffer));
	}

	~packageAnalyze() {

	}

	void addBuffer(char *pbuffer) {

		if(MAXSIZE - packageLength >= strlen(pbuffer)) {
			strcat(buffer, pbuffer);
		}

		else {
			
		}

	}

};