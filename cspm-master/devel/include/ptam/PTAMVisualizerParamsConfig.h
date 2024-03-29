//#line 2 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the ptam package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

#ifndef __ptam__PTAMVISUALIZERPARAMSCONFIG_H__
#define __ptam__PTAMVISUALIZERPARAMSCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace ptam
{
  class PTAMVisualizerParamsConfigStatics;
  
  class PTAMVisualizerParamsConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(PTAMVisualizerParamsConfig &config, const PTAMVisualizerParamsConfig &max, const PTAMVisualizerParamsConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const PTAMVisualizerParamsConfig &config1, const PTAMVisualizerParamsConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, PTAMVisualizerParamsConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const PTAMVisualizerParamsConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, PTAMVisualizerParamsConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const PTAMVisualizerParamsConfig &config) const = 0;
      virtual void getValue(const PTAMVisualizerParamsConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T PTAMVisualizerParamsConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (PTAMVisualizerParamsConfig::* field);

      virtual void clamp(PTAMVisualizerParamsConfig &config, const PTAMVisualizerParamsConfig &max, const PTAMVisualizerParamsConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const PTAMVisualizerParamsConfig &config1, const PTAMVisualizerParamsConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, PTAMVisualizerParamsConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const PTAMVisualizerParamsConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, PTAMVisualizerParamsConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const PTAMVisualizerParamsConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const PTAMVisualizerParamsConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, PTAMVisualizerParamsConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string name, std::string type, int parent, int id, bool s, T PT::* f) : AbstractGroupDescription(name, type, parent, id, s), field(f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, PTAMVisualizerParamsConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<PTAMVisualizerParamsConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(PTAMVisualizerParamsConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("ShowPC"==(*_i)->name){ShowPC = boost::any_cast<bool>(val);}
        if("ShowAllKFs"==(*_i)->name){ShowAllKFs = boost::any_cast<bool>(val);}
        if("ShowKFs"==(*_i)->name){ShowKFs = boost::any_cast<bool>(val);}
        if("KFLifetime"==(*_i)->name){KFLifetime = boost::any_cast<int>(val);}
        if("ShowPath"==(*_i)->name){ShowPath = boost::any_cast<bool>(val);}
        if("PathLength"==(*_i)->name){PathLength = boost::any_cast<int>(val);}
        if("ExportPC"==(*_i)->name){ExportPC = boost::any_cast<bool>(val);}
        if("ExportPrefix"==(*_i)->name){ExportPrefix = boost::any_cast<std::string>(val);}
        if("SaveMap"==(*_i)->name){SaveMap = boost::any_cast<bool>(val);}
        if("KFFlags"==(*_i)->name){KFFlags = boost::any_cast<int>(val);}
      }
    }

    bool ShowPC;
bool ShowAllKFs;
bool ShowKFs;
int KFLifetime;
bool ShowPath;
int PathLength;
bool ExportPC;
std::string ExportPrefix;
bool SaveMap;
int KFFlags;

    bool state;
    std::string name;

    
}groups;



//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool ShowPC;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool ShowAllKFs;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool ShowKFs;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int KFLifetime;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool ShowPath;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int PathLength;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool ExportPC;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      std::string ExportPrefix;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool SaveMap;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int KFFlags;
//#line 218 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("PTAMVisualizerParamsConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const PTAMVisualizerParamsConfig &__max__ = __getMax__();
      const PTAMVisualizerParamsConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const PTAMVisualizerParamsConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const PTAMVisualizerParamsConfig &__getDefault__();
    static const PTAMVisualizerParamsConfig &__getMax__();
    static const PTAMVisualizerParamsConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const PTAMVisualizerParamsConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void PTAMVisualizerParamsConfig::ParamDescription<std::string>::clamp(PTAMVisualizerParamsConfig &config, const PTAMVisualizerParamsConfig &max, const PTAMVisualizerParamsConfig &min) const
  {
    return;
  }

  class PTAMVisualizerParamsConfigStatics
  {
    friend class PTAMVisualizerParamsConfig;
    
    PTAMVisualizerParamsConfigStatics()
    {
PTAMVisualizerParamsConfig::GroupDescription<PTAMVisualizerParamsConfig::DEFAULT, PTAMVisualizerParamsConfig> Default("Default", "", 0, 0, true, &PTAMVisualizerParamsConfig::groups);
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ShowPC = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ShowPC = 1;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ShowPC = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("ShowPC", "bool", 0, "Show point cloud", "", &PTAMVisualizerParamsConfig::ShowPC)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("ShowPC", "bool", 0, "Show point cloud", "", &PTAMVisualizerParamsConfig::ShowPC)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ShowAllKFs = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ShowAllKFs = 1;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ShowAllKFs = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("ShowAllKFs", "bool", 0, "Show all keyframes ever made", "", &PTAMVisualizerParamsConfig::ShowAllKFs)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("ShowAllKFs", "bool", 0, "Show all keyframes ever made", "", &PTAMVisualizerParamsConfig::ShowAllKFs)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ShowKFs = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ShowKFs = 1;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ShowKFs = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("ShowKFs", "bool", 0, "Show keyframes", "", &PTAMVisualizerParamsConfig::ShowKFs)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("ShowKFs", "bool", 0, "Show keyframes", "", &PTAMVisualizerParamsConfig::ShowKFs)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.KFLifetime = 1;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.KFLifetime = 60000;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.KFLifetime = 1;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<int>("KFLifetime", "int", 0, "KF lifetime in sec", "", &PTAMVisualizerParamsConfig::KFLifetime)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<int>("KFLifetime", "int", 0, "KF lifetime in sec", "", &PTAMVisualizerParamsConfig::KFLifetime)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ShowPath = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ShowPath = 1;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ShowPath = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("ShowPath", "bool", 0, "Show path", "", &PTAMVisualizerParamsConfig::ShowPath)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("ShowPath", "bool", 0, "Show path", "", &PTAMVisualizerParamsConfig::ShowPath)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.PathLength = 1;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.PathLength = 60000;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.PathLength = 1000;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<int>("PathLength", "int", 0, "Number of path anchor points", "", &PTAMVisualizerParamsConfig::PathLength)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<int>("PathLength", "int", 0, "Number of path anchor points", "", &PTAMVisualizerParamsConfig::PathLength)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ExportPC = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ExportPC = 1;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ExportPC = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("ExportPC", "bool", 0, "export point cloud to file", "", &PTAMVisualizerParamsConfig::ExportPC)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("ExportPC", "bool", 0, "export point cloud to file", "", &PTAMVisualizerParamsConfig::ExportPC)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ExportPrefix = "";
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ExportPrefix = "";
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ExportPrefix = "";
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<std::string>("ExportPrefix", "str", 0, "prefix for export point cloud to file", "", &PTAMVisualizerParamsConfig::ExportPrefix)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<std::string>("ExportPrefix", "str", 0, "prefix for export point cloud to file", "", &PTAMVisualizerParamsConfig::ExportPrefix)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.SaveMap = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.SaveMap = 1;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.SaveMap = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("SaveMap", "bool", 0, "save full map to file", "", &PTAMVisualizerParamsConfig::SaveMap)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<bool>("SaveMap", "bool", 0, "save full map to file", "", &PTAMVisualizerParamsConfig::SaveMap)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.KFFlags = -100;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.KFFlags = 1;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.KFFlags = 0;
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<int>("KFFlags", "int", 0, "0:get all KFs, <0: get N newest KFs, 1: get new KFs only", "", &PTAMVisualizerParamsConfig::KFFlags)));
//#line 262 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr(new PTAMVisualizerParamsConfig::ParamDescription<int>("KFFlags", "int", 0, "0:get all KFs, <0: get N newest KFs, 1: get new KFs only", "", &PTAMVisualizerParamsConfig::KFFlags)));
//#line 233 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 233 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(PTAMVisualizerParamsConfig::AbstractGroupDescriptionConstPtr(new PTAMVisualizerParamsConfig::GroupDescription<PTAMVisualizerParamsConfig::DEFAULT, PTAMVisualizerParamsConfig>(Default)));
//#line 353 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<PTAMVisualizerParamsConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<PTAMVisualizerParamsConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    PTAMVisualizerParamsConfig __max__;
    PTAMVisualizerParamsConfig __min__;
    PTAMVisualizerParamsConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const PTAMVisualizerParamsConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static PTAMVisualizerParamsConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &PTAMVisualizerParamsConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const PTAMVisualizerParamsConfig &PTAMVisualizerParamsConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const PTAMVisualizerParamsConfig &PTAMVisualizerParamsConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const PTAMVisualizerParamsConfig &PTAMVisualizerParamsConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<PTAMVisualizerParamsConfig::AbstractParamDescriptionConstPtr> &PTAMVisualizerParamsConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<PTAMVisualizerParamsConfig::AbstractGroupDescriptionConstPtr> &PTAMVisualizerParamsConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const PTAMVisualizerParamsConfigStatics *PTAMVisualizerParamsConfig::__get_statics__()
  {
    const static PTAMVisualizerParamsConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = PTAMVisualizerParamsConfigStatics::get_instance();
    
    return statics;
  }

//#line 13 "/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PTAMVisualizerParams.cfg"
      const int PTAMVisualizerParams_SEND_PARAMETERS = 1;
}

#endif // __PTAMVISUALIZERPARAMSRECONFIGURATOR_H__
