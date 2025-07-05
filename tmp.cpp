#define MAXL (10) 

#include<cstring>
#include<string>

using namespace std;

class TrieNode {
public:
	bool isEnd, isRemove;
	int num;
	string s;
	TrieNode* parent;
	TrieNode* child[26];
}NodePool[15005*MAXL];

TrieNode* root;
int indx;
int maxWordiInPage;


void newNode(TrieNode* cur, char c) {
	indx++;
	NodePool[indx].parent = cur;
	NodePool[indx].isEnd = false;
	NodePool[indx].isRemove = false;
	NodePool[indx].num = 0;
	memset(NodePool[indx].child, NULL, sizeof(NodePool[indx].child));
	cur->child[c - 'a'] = &NodePool[indx];
}

void add(char *word)
{
	TrieNode* cur = root;
	string tmp = word;
	while (*word != '\0')
	{
		if (cur->child[*word - 'a'] == NULL)
		{
			newNode(cur, *word);
		}
		cur = cur->child[*word - 'a'];
		*word++;
	}

	if (!cur->isEnd)
	{
		cur->isEnd = true;
		cur->s = tmp;
		while (cur->parent != NULL)
		{
			cur->num++;
			cur = cur->parent;
		}
	}
}


void init(int N, char mWordList[][MAXL + 1], int mWordSize) {
	root = &NodePool[0];
	indx = 0;
	maxWordiInPage = N;
	memset(root->child, NULL, sizeof(root->child));

	for (int i = 0; i < mWordSize; i++)
	{
		add(mWordList[i]);
	}
}

void addWord(char mWordList[][MAXL + 1], int mWordSize)
{
	for (int i = 0; i < mWordSize; i++)
	{
		add(mWordList[i]);
	}
}

void remove(char* word)
{
	TrieNode* cur = root;
	string tmp = word;
	while (*word != '\0')
	{
		cur->child[*word - 'a']->num--;
		cur = cur->child[*word - 'a'];
		*word++;
	}

	cur->isRemove = true;
}

void removeWord(char mWordList[][MAXL + 1], int mWordSize)
{
	for (int i = 0; i < mWordSize; i++)
	{
		remove(mWordList[i]);
	}
}

char mRet[MAXL + 1];
bool kq;
void dequy(int target, TrieNode* cur)
{
	if (target < 0 || kq)
	{
		return;
	}

	if (target > 0)
	{
		if (cur->isEnd && !cur->isRemove)
		{
			target--;
		}
	}

	if (target == 0)
	{
		if (cur->isEnd && !cur->isRemove)
		{
			kq = true;
			for (int i = 0; i < cur->s.size(); i++)
			{
				mRet[i] = cur->s[i];
			}
			return;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (cur->child[i] != NULL)
		{
			if (cur->child[i]->num >= target)
			{
				cur = cur->child[i];
				dequy(target, cur);
			}
			else if (cur->child[i]->num < target) {
				target -= cur->child[i]->num;
			}
		}
	}
}

char* findWord(int mPageNum)
{
	memset(mRet, 0, sizeof(mRet));
	int target = (mPageNum - 1) * maxWordiInPage + 1;
	TrieNode* cur = root;
	kq = false;
	int cur_cnt = 0;
	dequy(target, cur);
	return mRet;
}


int findPage(char mWord[])
{
	TrieNode* cur = root;
	int cnt = 0;
	while (*mWord != '\0')
	{
		for (int i = 0; i < *mWord - 'a'; i++)
		{
			if (cur->child[i] != NULL)
			{
				cnt += cur->child[i]->num;
			}
		}
		cur = cur->child[*mWord - 'a'];
		if (cur->isEnd && !cur->isRemove)
			cnt++;
		*mWord++;
	}
	return (cnt + maxWordiInPage - 1) / maxWordiInPage;
}