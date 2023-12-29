#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/*
## ITEM_PROTO_MAKER_VERSION1 ##
## BY LYARCHON ##
## OLDGODSMT2 ##
*/

using namespace std;

int main()
{
	ofstream fileProto;
	int startChoice;
	int countNum = 0;
	int getVnum = 0;
	int handChoice;
	int goldBuy;
	int goldSell;
	int levelInput;
	int bonus1Choice;
	int	bonus1Val;
	int bonus2Choice;
	int	bonus2Val;
	int bonus3Choice;
	int	bonus3Val;
	int magicAttValueStart;
	int magicAttValueEnd;
	int	attackDamageStart;
	int	attackDamageEnd;
	int sockets;
	int addonType;
	int size;
	int refineNum = 9;
	int refineSet;
	int i = 0;
	char answerYn;
	int getVnumRef = getVnum + 1;
	string itemName;
	string itemType;
	string itemType2;
	string antiFlag;
	string wearFlag;
	string addBonus1;
	string addBonus2;
	string addBonus3;
	string antiSell = "NONE";
	vector<string> weaponBonus =
	{
		"APPLY_ATTBONUS_HUMAN",
		"APPLY_ATTBONUS_MONSTER",
		"APPLY_ATTBONUS_DEVIL",
		"APPLY_ATTBONUS_ANIMAL",
		"APPLY_ATTBONUS_ORC",
		"APPLY_STEAL_HP",
		"APPLY_CRITICAL_PCT",
		"APPLY_PENETRATE_PCT",
		"APPLY_MAX_HP",
		"APPLY_CON",
		"APPLY_INT",
		"APPLY_DEX",
		"APPLY_STR",
		"APPLY_ATT_SPEED",
		"APPLY_MOV_SPEED",
		"APPLY_CAST_SPEED",
		"APPLY_HP_REGEN",
		"APPLY_POISON_PCT"

	};
	vector<string> armorBonus =
	{
		"APPLY_ATTBONUS_HUMAN",
		"APPLY_ATTBONUS_MONSTER",
		"APPLY_ATTBONUS_DEVIL",
		"APPLY_ATTBONUS_ANIMAL",
		"APPLY_ATTBONUS_ORC",
		"APPLY_STEAL_HP",
		"APPLY_CRITICAL_PCT",
		"APPLY_PENETRATE_PCT",
		"APPLY_MAX_HP",
		"APPLY_CON",
		"APPLY_INT",
		"APPLY_DEX",
		"APPLY_STR",
		"APPLY_ATT_SPEED",
		"APPLY_MOV_SPEED",
		"APPLY_CAST_SPEED",
		"APPLY_HP_REGEN",
		"APPLY_POISON_PCT"
		"APPLY_RESIST_SWORD",
		"APPLY_RESIST_TWOHAND",
		"APPLY_RESIST_DAGGER",
		"APPLY_RESIST_BELL"

	};
	fileProto.open("item_proto.txt");
	cout << "[1] Weapon Maker [2] Armor Maker" << endl;
	cin >> startChoice;
	switch (startChoice)
	{
	case 1: //weapon start
		wearFlag = "WEAR_WEAPON";
		antiFlag = "ANTI_MUDANG";
		itemType = "ITEM_WEAPON";
		cout << "[1]1Hand sword or [2]2Hand sword [3]Ninja Dagger [4]Ninja Bow" << endl;
		cin >> handChoice;
		if (handChoice == 1) {
			itemType2 = "WEAPON_SWORD";
			size = 2;
		}
		else if (handChoice == 2) {
			antiFlag = "ANTI_MUSA | ANTI_ASSASSIN | ANTI_SURA";
			itemType2 = "WEAPON_TWO_HANDED";
			size = 3;
		}
		else if (handChoice == 3)
		{
			antiFlag = "ANTI_MUSA | ANTI_SURA | ANTI_MUDANG";
			itemType2 = "WEAPON_DAGGER";
			size = 1;
		}
		else if (handChoice == 4)
		{
			antiFlag = "ANTI_MUSA | ANTI_SURA | ANTI_MUDANG";
			itemType2 = "WEAPON_BOW";
			size = 2;

		}
		cout << "Enter VNUM wanted" << endl;
		cin >> getVnum;
		cout << "Enter Item name" << endl;
		cin.ignore();
		getline(cin, itemName);
		cout << "Buy from Vendor price" << endl;
		cin >> goldBuy;
		cout << "Sell from Vendor price" << endl;
		cin >> goldSell;
		cout << "Enter wanted item level" << endl;
		cin >> levelInput;
		cout << "Chooce your 1st bonus" << endl;
		for (auto val : weaponBonus)
		{
			countNum++;
				cout << "[" << countNum << "]" << val << endl;
		}
		cin >> bonus1Choice;
		addBonus1 = weaponBonus.at(bonus1Choice - 1);
		cout << "Enter value of " << addBonus1 << endl;
		cin >> bonus1Val;
		cout << "Chooce your 2st bonus" << endl;
		countNum = 0;
		for (auto val : weaponBonus)
		{
			countNum++;
			cout << "[" << countNum << "]" << val << endl;
		}
		cin >> bonus2Choice;
		addBonus2 = weaponBonus.at(bonus2Choice - 1);
		cout << "Enter value of " << addBonus2 << endl;
		cin >> bonus2Val;
		cout << "Chooce your 3st bonus" << endl;
		countNum = 0;
		for (auto val : weaponBonus)
		{
			countNum++;
			cout << "[" << countNum << "]" << val << endl;
		}
		cin >> bonus3Choice;
		addBonus3 = weaponBonus.at(bonus3Choice - 1);
		cout << "Enter value of " << addBonus3 << endl;
		cin >> bonus3Val;
		cout << "Enter magic attack value minimum" << endl;
		cin >> magicAttValueStart;
		cout << "Enter magic attack value maximum" << endl;
		cin >> magicAttValueEnd;
		cout << "Enter Attack Damage value minimum" << endl;
		cin >> attackDamageStart;
		cout << "Enter Attack Damage value maximum" << endl;
		cin >> attackDamageEnd;
		cout << "Enter desired number sockets " << endl;
		cin >> sockets;
		cout << "Enter addon type [1]With avg Dmg possibility [2] without avg dmg possibility " << endl;
		cin >> addonType;
		if (addonType == 1) {
			addonType = -1;

		}
		else {
			addonType = 0;
		}
		cout << "Do you want to be tunable till +9 Y/N?";
		cin >> answerYn;
		cout << "Enter your refine_set (materials needed) number" << endl;
		cin >> refineSet;
		if (answerYn == 'y') { // LOOP +9 start
			countNum = 0;
			while (i <= refineNum)

			{

				fileProto << getVnum << "	" << itemName << "+" << countNum << "	" << itemType << "	" << itemType2
					<< "	" << size << "	" << antiFlag << "	" << antiSell << "	" << "ITEM_TUNABLE" << "	" << wearFlag << "	" << "NONE"
					<< "	" << goldBuy << "	" << goldSell << "	" << getVnumRef << "	 " << refineSet << "	" << 15 << "	"
					<< "LEVEL" << "	" << levelInput << "	" << "LIMIT_NONE" << "	" << 0 << "	 " << addBonus1 << "	" << bonus1Val
					<< "	" << addBonus2 << "	" << bonus2Val << "	" << addBonus3 << "	" << bonus3Val << "	" << 0
					<< "	" << magicAttValueStart << "	" << magicAttValueEnd << "	" << attackDamageStart << "	" << attackDamageEnd << "	" << sockets << "	" << addonType << endl;

				getVnum++;
				countNum++;
				refineSet++;
				i++;
			}
		}
		else {
			fileProto << getVnum << "	" << itemName << "	" << itemType << "	" << itemType2
				<< "	" << size << "	" << antiFlag << "	" << antiSell << "	" << "ITEM_TUNABLE" << "	" << wearFlag << "	" << "NONE"
				<< "	" << goldBuy << "	" << goldSell << "	" << 0 << "	 " << 0 << "	" << 15 << "	"
				<< "LEVEL" << "	" << levelInput << "	" << "LIMIT_NONE" << "	" << 0 << "	 " << addBonus1 << "	" << bonus1Val
				<< "	" << addBonus2 << "	" << bonus2Val << "	" << addBonus3 << "	" << bonus3Val << "	" << 0
				<< "	" << magicAttValueStart << "	" << magicAttValueEnd << "	" << attackDamageStart << "	" << attackDamageEnd << "	" << sockets << "	" << addonType;
		}
		fileProto.close();
		break; // weapon end
	case 2: // ARMOR START 
		wearFlag = "WEAR_BODY";
		itemType = "ITEM_ARMOR";
		itemType2 = "ARMOR_BODY";
		cout << "[1]Warrior Armor [2]Ninja Armor [3]Sura armor [4]Shaman armor" << endl;
		cin >> handChoice;
		if (handChoice == 1) {
			antiFlag = "ANTI_ASSASSIN | ANTI_SURA | ANTI_MUDANG |";
			size = 2;
		}
		else if (handChoice == 2) {
			antiFlag = "ANTI_MUSA | ANTI_SURA | ANTI_MUDANG |";
			size = 2;
		}
		else if (handChoice == 3)
		{
			antiFlag = "ANTI_MUSA | ANTI_ASSASSIN | ANTI_MUDANG |";
			size = 2;
		}
		else if (handChoice == 4)
		{
			antiFlag = "ANTI_MUSA | ANTI_ASSASSIN | ANTI_SURA |";
			size = 2;

		}
		cout << "Enter VNUM wanted" << endl;
		cin >> getVnum;
		cout << "Enter Item name" << endl;
		cin.ignore();
		getline(cin, itemName);
		cout << "Buy from Vendor price" << endl;
		cin >> goldBuy;
		cout << "Sell from Vendor price" << endl;
		cin >> goldSell;
		cout << "Enter wanted item level" << endl;
		cin >> levelInput;
		cout << "Chooce your 1st bonus" << endl;
		for (auto val : weaponBonus)
		{
			countNum++;
			cout << "[" << countNum << "]" << val << endl;
		}
		cin >> bonus1Choice;
		addBonus1 = weaponBonus.at(bonus1Choice - 1);
		cout << "Enter value of " << addBonus1 << endl;
		cin >> bonus1Val;
		cout << "Chooce your 2st bonus" << endl;
		countNum = 0;
		for (auto val : weaponBonus)
		{
			countNum++;
			cout << "[" << countNum << "]" << val << endl;
		}
		cin >> bonus2Choice;
		addBonus2 = weaponBonus.at(bonus2Choice - 1);
		cout << "Enter value of " << addBonus2 << endl;
		cin >> bonus2Val;
		cout << "Chooce your 3st bonus" << endl;
		countNum = 0;
		for (auto val : weaponBonus)
		{
			countNum++;
			cout << "[" << countNum << "]" << val << endl;
		}
		cin >> bonus3Choice;
		addBonus3 = weaponBonus.at(bonus3Choice - 1);
		cout << "Enter value of " << addBonus3 << endl;
		cin >> bonus3Val;
		cout << "Enter magic attack value minimum" << endl;
		cin >> magicAttValueStart;
		cout << "Enter magic attack value maximum" << endl;
		cin >> magicAttValueEnd;
		cout << "Enter Attack Damage value minimum" << endl;
		cin >> attackDamageStart;
		cout << "Enter Attack Damage value maximum" << endl;
		cin >> attackDamageEnd;
		cout << "Enter desired number sockets " << endl;
		cin >> sockets;
		cout << "Enter addon type [1]With avg Dmg possibility [2] without avg dmg possibility " << endl;
		cin >> addonType;
		if (addonType == 1) {
			addonType = -1;

		}
		else {
			addonType = 0;
		}
		cout << "Do you want to be tunable till +9 Y/N?";
		cin >> answerYn;
		cout << "Enter your refine_set (materials needed) number" << endl;
		cin >> refineSet;
		if (answerYn == 'y') { // LOOP +9 start
			countNum = 0;
			while ( i <= refineNum)
	
			{
			
				fileProto << getVnum << "	" << itemName << "+" << countNum << "	" << itemType << "	" << itemType2
					<< "	" << size << "	" << antiFlag << "	" << antiSell << "	" << "ITEM_TUNABLE" << "	"  << wearFlag << "	" << "NONE"
					<< "	" << goldBuy << "	" << goldSell << "	" << getVnumRef << "	 " << refineSet << "	" << 15 << "	"
					<< "LEVEL" << "	" << levelInput << "	" << "LIMIT_NONE" << "	" << 0 << "	 " << addBonus1 << "	" << bonus1Val
					<< "	" << addBonus2 << "	" << bonus2Val << "	" << addBonus3 << "	" << bonus3Val << "	" << 0
					<< "	" << magicAttValueStart << "	" << magicAttValueEnd << "	" << attackDamageStart << "	" << attackDamageEnd << "	" << sockets << "	" << addonType << endl;

				getVnum++;
				countNum++;
				refineSet++;
				i++;
			}
		} else {
		fileProto << getVnum << "	" << itemName << "	" << itemType << "	" << itemType2
			<< "	" << size << "	" << antiFlag << "	" << antiSell << "	" << "ITEM_TUNABLE" << "	" << wearFlag << "	" << "NONE"
			<< "	" << goldBuy << "	" << goldSell << "	" << 0 << "	 " << 0 << "	" << 15 << "	"
			<< "LEVEL" << "	" << levelInput << "	" << "LIMIT_NONE" << "	" << 0 << "	 " << addBonus1 << "	" << bonus1Val
			<< "	" << addBonus2 << "	" << bonus2Val << "	" << addBonus3 << "	" << bonus3Val << "	" << 0
			<< "	" << magicAttValueStart << "	" << magicAttValueEnd << "	" << attackDamageStart << "	" << attackDamageEnd << "	" << sockets << "	" << addonType;
		}
		fileProto.close();
		break; // ARMOR END
	}


}

