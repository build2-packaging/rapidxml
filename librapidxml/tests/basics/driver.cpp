#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <rapidxml/rapidxml_iterators.hpp>
#include <rapidxml/rapidxml_utils.hpp>

#include <iterator>
#include <string>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace rapidxml;

  char text[] = "<?xml version='1.0'?><root id='1'><child>hi</child></root>";

  xml_document<> doc;
  doc.parse<0> (text);

  xml_node<>* root (doc.first_node ("root"));
  assert (root != nullptr);
  assert (root->first_attribute ("id") != nullptr);
  assert (root->first_node ("child") != nullptr);

  node_iterator<char> b (root);
  node_iterator<char> e;
  assert (b != e);

  std::string out;
  print (std::back_inserter (out), doc, print_no_indenting);
  assert (out.find ("<root") != std::string::npos);
  assert (out.find ("hi") != std::string::npos);

  // xml:space="preserve" must survive parse_trim_whitespace, as cereal relies
  // on. Unmarked text is still trimmed.
  //
  {
    char space[] =
      "<root>"
      "<plain>  hi  </plain>"
      "<kept xml:space='preserve'>  hi  </kept>"
      "</root>";

    xml_document<> d;
    d.parse<parse_trim_whitespace | parse_no_data_nodes> (space);

    xml_node<>* plain (d.first_node ("root")->first_node ("plain"));
    xml_node<>* kept (d.first_node ("root")->first_node ("kept"));
    assert (plain != nullptr && kept != nullptr);
    assert (std::string (plain->value (), plain->value_size ()) == "hi");
    assert (std::string (kept->value (), kept->value_size ()) == "  hi  ");
  }
}
