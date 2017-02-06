###How to Configure Multibanners

1. Modules: Require multibanners module, focal_point module, inline_entity_form module, and unslider library in project composer.json
2. Install multibanners module
3. Set "banner" entity permissions
4. Add field_banners_ref to desired node type so that:
  a) "Required field" can be left unchecked OR can be checked (optional)
  b) Leave "Reference method" as "default"
  c) Leave "Create referenced entities if they don't already exist" unchecked
  d) "Sort by" is optional
5. Optionally: add field_banners_type to desired node type
  a) "Required field" can be left unchecked OR can be checked (optional)
  b) "Default value" can be left "- None -", or set to a value in the list.
6. Set node form display so that:
  a) field_banners_ref is a "Inline entity form - Complex" that:
    i) Form mode is "default"
    ii) "Allow users to add new banner entities." is checked
    iii) "Allow users to add existing banner entities." is checked
    iv) "Autocomplete matching" can be anything
6. Set node view display(s) so that:
  a) field_banners_ref and field_banners_type (if present) are hidden
7. Set multibanner blocks to desired region(s)
  a) Visiblity settings are optional.
