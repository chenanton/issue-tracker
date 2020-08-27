/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "entry.h"
#include "issue.h"

using namespace std;

class Group : public Entry {
    vector<Entry*> subentries;

   public:
    // Constructors
    Group(int pid, string t);
    Group(int id, int pid, string cd, string t);
    Group(int id, int pid, string cd, string t, vector<Entry*> es);

    Group(const Group& g);

    // Destructor
    ~Group();

    // Copy assignment
    Group& operator=(const Group& g);

    // Get fields
    const vector<Entry*>& get_subentries() { return subentries; }

    // Edit fields
    void set_repository(string r);
    bool add_entry(Entry* e);
    void add_new_issue(string t, string d, string r);
    void add_new_group(string t);
    bool delete_entry(int id) override;

    void activate();
    void deactivate();

    // Auxiliary methods
    void print_info(const int level = 0) const;

    bool save_to_file(string file_path, bool overwrite = true) override;

    Entry* get_copy() const override;
    void copy(const Group& g);
    void clear() override;
};