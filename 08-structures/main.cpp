#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;

struct Train
{
	string destination;
	int number;
	string departure_time;
};

bool IsTime(string time);
void InputTrain(Train train[], const int kNumTrains);
void SortTrain(Train train[], const int kNumTrains);
void PrintTrain(Train train[], const int kNumTrains);
void PrintTimeAfter(Train train[], const int kNumTrains, string time);

int main()
{
	const int kNumTrains = 8;
	Train train[kNumTrains];

	InputTrain(train, kNumTrains);

	SortTrain(train, kNumTrains);
	PrintTrain(train, kNumTrains);


	string time;
repeat:
	cout << "\nSelect time: ";
	cin >> time;
	if (!IsTime(time))
	{
		cout << "\nInvalid time. Use format hh:mm!";
		goto repeat;
	}
	cout << "\nTrains starting after this time:\n";
	PrintTimeAfter(train, kNumTrains, time);

	return 0;
}

bool IsTime(string time)
{
	if (regex_match(time, regex("([0-1][0-9]|2[0-3]):[0-5][0-9]")))
		return 1;
	else
		return 0;
}

void InputTrain(Train train[], const int kNumTrains)
{
	for (int i = 0; i < kNumTrains; i++)
	{
		cout << i + 1 << ". Train \n";
		cout << "Enter train destination (e.g. New York): ";
		getline(cin, train[i].destination);
		cout << "Enter number of the train (e.g. 28): ";
		cin >> train[i].number;
	repeat:
		cout << "Enter departure time (e.g. 12:15): ";
		cin >> train[i].departure_time;
		if (!IsTime(train[i].departure_time))
		{
			cout << "\nInvalid time. Use format hh:mm!\n";
			goto repeat;
		}
		cout << endl;
		cin.ignore();
	}
}

void PrintTrain(Train train[], const int kNumTrains)
{
	cout << string(41, '-') << endl;
	cout << "| Number | Destination | Departure time |\n";
	cout << string(41, '-') << endl;
	for (int i = 0; i < kNumTrains; i++)
	{
		cout << "|" << setw(8) << train[i].number;
		cout << "|" << setw(13) << train[i].destination;
		cout << "|" << setw(16) << train[i].departure_time << "|\n";
		cout << string(41, '-') << endl;
	}
}

void SortTrain(Train train[], const int kNumTrains)
{
	for (int i = 0; i < kNumTrains - 1; i++)
		for (int j = 0; j < kNumTrains - i - 1; j++)
			if (train[j].destination.compare(train[j + 1].destination) > 0)
				swap(train[j], train[j + 1]);
}

void PrintTimeAfter(Train train[], const int kNumTrains, string time)
{
	cout << string(41, '-') << endl;
	cout << "| Number | Destination | Departure time |\n";
	cout << string(41, '-') << endl;

	bool no_trains = true;
	for (int i = 0; i < kNumTrains; i++)
	{
		if ((train[i].departure_time).compare(time) > 0)
		{
			no_trains = false;			

			cout << "|" << setw(8) << train[i].number;
			cout << "|" << setw(13) << train[i].destination;
			cout << "|" << setw(16) << train[i].departure_time << "|\n";
			cout << string(41, '-') << endl;
		}
	}

	if (no_trains)
		cout << "No trains were found!\n";
}