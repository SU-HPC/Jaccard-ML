//
// Created by Amro on 3/28/2022.
//

#ifndef JACCARD_ML_IO_H
#define JACCARD_ML_IO_H
#include "json.h"
#include "utility"
#include "time.h"
#include <iostream>
#include <fstream>

JSONWrapper& operator<<(JSONWrapper& j, std::pair<std::string, std::string> data){
   j.Use(data.first, data.second, true);
   return j;
}
JSONWrapper get_result_json(double time, unsigned long long errors){
    JSONWrapper output;
    output.Use("time",time, true);
    output.Use("errors", errors, true);
    time_t time_obj = time;
    output.Set("timestamp", ctime(&time_obj));
    return output;
}

JSONWrapper initialize_output_json(std::string graph_name){
    JSONWrapper metadata;
    metadata.Use("graph name", graph_name, true);
    JSONWrapper j;
    j.SetJSON("metadata",  metadata);
    j.SetJSON("experiments", JSONWrapper());
    return j;
}

JSONWrapper read_json(std::string filename){
    std::ifstream fin(filename);
    JSONWrapper output_json;
    fin >> output_json;
    return output_json;
}

void write_json_to_file(std::string filename, JSONWrapper& output_json){
    std::ofstream out(filename);
    out << output_json;
}

#endif //JACCARD_ML_IO_H
