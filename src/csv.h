#define CSV_PATH "../hackathons.csv"
#define COLUMN_DELIMITER ','

const char* columnEnd(const char *str, char delimiter);
int countColumns(const char *row, char delimiter);