## *********************************************************
## 
## File autogenerated for the ptam package 
## by the dynamic_reconfigure package.
## Please do not edit.
## 
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'upper': 'DEFAULT', 'lower': 'groups', 'srcline': 233, 'name': 'Default', 'parent': 0, 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'cstate': 'true', 'parentname': 'Default', 'class': 'DEFAULT', 'field': 'default', 'state': True, 'parentclass': '', 'groups': [], 'parameters': [{'srcline': 262, 'description': 'Scale', 'max': 30.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'Scale', 'edit_method': '', 'default': 1.0, 'level': 0, 'min': 0.01, 'type': 'double'}, {'srcline': 262, 'description': 'selects the source for the motion model.', 'max': '', 'cconsttype': 'const char * const', 'ctype': 'std::string', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'MotionModelSource', 'edit_method': "{'enum_description': 'An enum to set wich input to use for the motion model.', 'enum': [{'srcline': 28, 'description': 'use constant motion model.', 'srcfile': '/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PtamParams.cfg', 'cconsttype': 'const char * const', 'value': 'CONSTANT', 'ctype': 'std::string', 'type': 'str', 'name': 'MM_CONSTANT'}, {'srcline': 29, 'description': 'use imu orientation for the motion model.', 'srcfile': '/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PtamParams.cfg', 'cconsttype': 'const char * const', 'value': 'IMU', 'ctype': 'std::string', 'type': 'str', 'name': 'MM_IMU'}, {'srcline': 30, 'description': 'use full pose estimated externally for motion model.', 'srcfile': '/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PtamParams.cfg', 'cconsttype': 'const char * const', 'value': 'FULL_POSE', 'ctype': 'std::string', 'type': 'str', 'name': 'MM_FULL_POSE'}]}", 'default': 'CONSTANT', 'level': 0, 'min': '', 'type': 'str'}, {'srcline': 262, 'description': 'max features per frame', 'max': 1000.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'MaxPatchesPerFrame', 'edit_method': '', 'default': 500.0, 'level': 0, 'min': 10.0, 'type': 'double'}, {'srcline': 262, 'description': "'distance' after which a new kf is requested", 'max': 10.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'MaxKFDistWiggleMult', 'edit_method': '', 'default': 3.0, 'level': 0, 'min': 0.1, 'type': 'double'}, {'srcline': 262, 'description': 'use AutoInitPixel as new KF request criteria', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'UseKFPixelDist', 'edit_method': '', 'default': False, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 262, 'description': 'do not add map points at level zero', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'NoLevelZeroMapPoints', 'edit_method': '', 'default': False, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 262, 'description': 'depth variance to search for features', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'EpiDepthSearchMaxRange', 'edit_method': '', 'default': 100.0, 'level': 0, 'min': 1.0, 'type': 'double'}, {'srcline': 262, 'description': 'min number of features for coarse tracking', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'CoarseMin', 'edit_method': '', 'default': 20.0, 'level': 0, 'min': 1.0, 'type': 'double'}, {'srcline': 262, 'description': 'max number of features for coarse tracking', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'CoarseMax', 'edit_method': '', 'default': 60.0, 'level': 0, 'min': 1.0, 'type': 'double'}, {'srcline': 262, 'description': 'Pixel search radius for coarse features', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'CoarseRange', 'edit_method': '', 'default': 30.0, 'level': 0, 'min': 1.0, 'type': 'double'}, {'srcline': 262, 'description': 'coarse tracking sub-pixel iterations', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'CoarseSubPixIts', 'edit_method': '', 'default': 8.0, 'level': 0, 'min': 1.0, 'type': 'double'}, {'srcline': 262, 'description': 'enable/disable coarse tracking', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'DisableCoarse', 'edit_method': '', 'default': False, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 262, 'description': 'speed above which coarse stage is used', 'max': 1.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'CoarseMinVelocity', 'edit_method': '', 'default': 0.006, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 262, 'description': 'min ratio features visible/features found for good tracking', 'max': 1.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'TrackingQualityGood', 'edit_method': '', 'default': 0.3, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 262, 'description': 'max ratio features visible/features found before lost', 'max': 1.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'TrackingQualityLost', 'edit_method': '', 'default': 0.13, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 262, 'description': 'min pixels to be found for good tracking', 'max': 1000, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'TrackingQualityFoundPixels', 'edit_method': '', 'default': 100, 'level': 0, 'min': 1, 'type': 'int'}, {'srcline': 262, 'description': 'max iterations for bundle adjustment', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'MaxIterations', 'edit_method': '', 'default': 20.0, 'level': 0, 'min': 1.0, 'type': 'double'}, {'srcline': 262, 'description': 'number of keyframes kept in the map (0 or 1 = inf)', 'max': 1000, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'MaxKF', 'edit_method': '', 'default': 0, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': 'bundleadjustment method', 'max': '', 'cconsttype': 'const char * const', 'ctype': 'std::string', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'BundleMethod', 'edit_method': "{'enum_description': 'An enum to set the bundle adjustment mode.', 'enum': [{'srcline': 14, 'description': 'local and global bundle adjustment', 'srcfile': '/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PtamParams.cfg', 'cconsttype': 'const char * const', 'value': 'LOCAL_GLOBAL', 'ctype': 'std::string', 'type': 'str', 'name': 'LOCAL_GLOBAL'}, {'srcline': 15, 'description': 'local bundle adjustment only', 'srcfile': '/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PtamParams.cfg', 'cconsttype': 'const char * const', 'value': 'LOCAL', 'ctype': 'std::string', 'type': 'str', 'name': 'LOCAL'}, {'srcline': 16, 'description': 'global bundle adjustment only', 'srcfile': '/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PtamParams.cfg', 'cconsttype': 'const char * const', 'value': 'GLOBAL', 'ctype': 'std::string', 'type': 'str', 'name': 'GLOBAL'}]}", 'default': 'LOCAL_GLOBAL', 'level': 0, 'min': '', 'type': 'str'}, {'srcline': 262, 'description': 'limit for convergence in bundle adjustment', 'max': 1.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'UpdateSquaredConvergenceLimit', 'edit_method': '', 'default': 1e-06, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 262, 'description': 'print bundle debug messages', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'BundleDebugMessages', 'edit_method': '', 'default': False, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 262, 'description': 'FAST corner method', 'max': '', 'cconsttype': 'const char * const', 'ctype': 'std::string', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'FASTMethod', 'edit_method': "{'enum_description': 'An enum to set the FAST corner extraction method.', 'enum': [{'srcline': 20, 'description': 'FAST 9', 'srcfile': '/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PtamParams.cfg', 'cconsttype': 'const char * const', 'value': 'FAST9', 'ctype': 'std::string', 'type': 'str', 'name': 'FAST9'}, {'srcline': 21, 'description': 'FAST 10', 'srcfile': '/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PtamParams.cfg', 'cconsttype': 'const char * const', 'value': 'FAST10', 'ctype': 'std::string', 'type': 'str', 'name': 'FAST10'}, {'srcline': 22, 'description': 'FAST 9 with nonmax suppression', 'srcfile': '/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PtamParams.cfg', 'cconsttype': 'const char * const', 'value': 'FAST9_nonmax', 'ctype': 'std::string', 'type': 'str', 'name': 'FAST9_nonmax'}, {'srcline': 23, 'description': 'AGAST 12 pixel diamond', 'srcfile': '/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PtamParams.cfg', 'cconsttype': 'const char * const', 'value': 'AGAST12d', 'ctype': 'std::string', 'type': 'str', 'name': 'AGAST12d'}, {'srcline': 24, 'description': 'AGAST 16 pixel circular', 'srcfile': '/home/meng/cspm/src/ethzasl_ptam/ptam/cfg/PtamParams.cfg', 'cconsttype': 'const char * const', 'value': 'OAST16', 'ctype': 'std::string', 'type': 'str', 'name': 'OAST16'}]}", 'default': 'FAST9_nonmax', 'level': 0, 'min': '', 'type': 'str'}, {'srcline': 262, 'description': 'threshold for FAST features on level 0', 'max': 255, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'Thres_lvl0', 'edit_method': '', 'default': 10, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': 'threshold for FAST features on level 1', 'max': 255, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'Thres_lvl1', 'edit_method': '', 'default': 15, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': 'threshold for FAST features on level 2', 'max': 255, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'Thres_lvl2', 'edit_method': '', 'default': 15, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': 'threshold for FAST features on level 3', 'max': 255, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'Thres_lvl3', 'edit_method': '', 'default': 10, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': 'adaptive threshold for corner extraction', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'AdaptiveThrs', 'edit_method': '', 'default': False, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 262, 'description': 'controls adaptive threshold to MaxPatches*N corners', 'max': 20.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'AdaptiveThrsMult', 'edit_method': '', 'default': 5.0, 'level': 0, 'min': 0.5, 'type': 'double'}, {'srcline': 262, 'description': 'small images for the rotation estimator blur', 'max': 10.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'RotationEstimatorBlur', 'edit_method': '', 'default': 0.75, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 262, 'description': 'small images for the rotation estimator enable/disable', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'UseRotationEstimator', 'edit_method': '', 'default': True, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 262, 'description': 'MiniPatch tracking threshhold', 'max': 10000000, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'MiniPatchMaxSSD', 'edit_method': '', 'default': 100000, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': 'number of dominant plane RANSACs', 'max': 1000, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'PlaneAlignerRansacs', 'edit_method': '', 'default': 100, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': 'score for relocalization', 'max': 90000000, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'RelocMaxScore', 'edit_method': '', 'default': 9000000, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': 'enable auto initialization', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'AutoInit', 'edit_method': '', 'default': False, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 262, 'description': 'check map point variance for initial map', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'CheckInitMapVar', 'edit_method': '', 'default': False, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 262, 'description': 'min pixel distance for auto initialization', 'max': 100, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'AutoInitPixel', 'edit_method': '', 'default': 20, 'level': 0, 'min': 1, 'type': 'int'}, {'srcline': 262, 'description': 'max # of loops for stereo initialization', 'max': 100, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'MaxStereoInitLoops', 'edit_method': '', 'default': 10, 'level': 0, 'min': 1, 'type': 'int'}], 'type': '', 'id': 0}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])    
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

PtamParams_LOCAL_GLOBAL = 'LOCAL_GLOBAL'
PtamParams_LOCAL = 'LOCAL'
PtamParams_GLOBAL = 'GLOBAL'
PtamParams_FAST9 = 'FAST9'
PtamParams_FAST10 = 'FAST10'
PtamParams_FAST9_nonmax = 'FAST9_nonmax'
PtamParams_AGAST12d = 'AGAST12d'
PtamParams_OAST16 = 'OAST16'
PtamParams_MM_CONSTANT = 'CONSTANT'
PtamParams_MM_IMU = 'IMU'
PtamParams_MM_FULL_POSE = 'FULL_POSE'
PtamParams_SEND_PARAMETERS = 1
